% lab1_figure_generator.m
% Lab 1 Figure Generator
% 
% Author information:
%   Name: Josh Brake
%   Contact: jbrake@hmc.edu
%   Created: 2023-01-21
%   Last Update: 2023-01-21
%
% 
% Purpose: This script loads data from a file and generates a figure 
%   plotting the elevation from the gpx track vs. elapsed time.
%
%
%% Import data

trk = gpxread("example-data.gpx");

timeStr = strrep(trk.Time,'.000Z','');
t = datetime(timeStr);
elapsedTime_min = minutes(t - t(1));

elevation_m = trk.Elevation;
relative_elevation_m = elevation_m - elevation_m(1);
%% Distance vs. elapsed time

figure
plot(elapsedTime_min(1:4175), relative_elevation_m(1:4175), 'LineWidth',2);
xlabel('Elapsed Time [min]','FontSize',16);
ylabel('Elevation [meters]','FontSize',16);

% Set axis font size
ax = gca;
ax.FontSize = 14;

% Set title
ax.Title.String = "Relative Elevation vs. Elapsed Time";

%% Save figure to file

% Save as raster and vector
exportgraphics(gca, 'lab1_figure_example.png', 'Resolution',300); % Save at resolution of at least 300 dots per inch (DPI)
exportgraphics(gca, 'lab1_figure_example.pdf'); % Save as vector
