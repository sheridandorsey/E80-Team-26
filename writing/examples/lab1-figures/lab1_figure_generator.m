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